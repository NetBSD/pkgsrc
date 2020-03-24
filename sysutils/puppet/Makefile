# $NetBSD: Makefile,v 1.39 2020/03/24 18:27:42 taca Exp $

DISTNAME=		puppet-6.14.0
CATEGORIES=		sysutils
#MASTER_SITES=		http://puppetlabs.com/downloads/puppet/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.puppetlabs.com/
COMMENT=		Configuration management framework written in Ruby
LICENSE=		apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-facter>=2.0.1<5:../../sysutils/ruby-facter
DEPENDS+=	${RUBY_PKGPREFIX}-hiera>=3.2.1<4:../../databases/ruby-hiera
DEPENDS+=	${RUBY_PKGPREFIX}-semantic_puppet>=1.0<2:../../devel/ruby-semantic_puppet
DEPENDS+=	${RUBY_PKGPREFIX}-fast_gettext>=1.1:../../devel/ruby-fast_gettext
DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.1<3:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.10<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-httpclient>=2.8<3:../../www/ruby-httpclient
DEPENDS+=	${RUBY_PKGPREFIX}-puppet-resource_api>=1.5<2:../../sysutils/ruby-puppet-resource_api
DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0<2:../../devel/ruby-concurrent-ruby
DEPENDS+=	${RUBY_PKGPREFIX}-deep_merge>=1.0<2:../../devel/ruby-deep_merge

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	fast_gettext>=1.1
USE_LANAUGES=		# none

PKG_SYSCONFSUBDIR=	puppet
RCD_SCRIPTS=		puppetd puppetmasterd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	install.rb
SUBST_FILES.prefix+=	lib/puppet/face/module/changes.rb
SUBST_FILES.prefix+=	lib/puppet/face/module/install.rb
SUBST_FILES.prefix+=	lib/puppet/face/module/list.rb
SUBST_FILES.prefix+=	lib/puppet/face/module/uninstall.rb
SUBST_FILES.prefix+=	lib/puppet/face/module/upgrade.rb
SUBST_FILES.prefix+=	lib/puppet/reference/configuration.rb
SUBST_FILES.prefix+=	lib/puppet/util/run_mode.rb
SUBST_FILES.prefix+=	ext/solaris/smf/puppetd.xml
SUBST_FILES.prefix+=	ext/solaris/smf/puppetmasterd.xml
SUBST_FILES.prefix+=	man/man5/puppet.conf.5
SUBST_FILES.prefix+=	man/man8/puppet-apply.8
SUBST_FILES.prefix+=	man/man8/puppet-module.8
SUBST_FILES.prefix+=	man/man8/puppet-parser.8
SUBST_FILES.prefix+=	spec/unit/util/run_mode_spec.rb
SUBST_FILES.prefix+=	spec/unit/util/selinux_spec.rb
SUBST_SED.prefix=	-e "s|/etc/puppet|${PKG_SYSCONFDIR}|g"
SUBST_SED.prefix+=	-e "s|/opt/csw/lib|${PREFIX}/lib|g"

SUBST_CLASSES+=		sufx
SUBST_STAGE.sufx=	pre-configure
SUBST_MESSAGE.sufx=	Fixing command suffix
SUBST_FILES.sufx=	lib/puppet/util/command_line.rb
SUBST_VARS.sufx=	RUBY_SUFFIX

EGDIR=			share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/puppet.conf ${PKG_SYSCONFDIR}/puppet.conf

## Since these users are needed only for puppet server,
## puppet-server package should be created.
#SUBST_CLASSES+=		user
#SUBST_STAGE.user=		post-patch
#SUBST_FILES.user=		lib/puppet/defaults.rb
#SUBST_SED.user=		-e "s|@PUPPET_GROUP@|${PUPPET_GROUP}|g"
#SUBST_SED.user+=		-e "s|@PUPPET_USER@|${PUPPET_USER}|g"
#
#PKG_GROUPS_VARS=		PUPPET_GROUP
#PKG_USERS_VARS=		PUPPET_USER
#
#PKG_GROUPS=			${PUPPET_GROUP}
#PKG_USERS=			${PUPPET_USER}:${PUPPET_GROUP}
#PKG_GECOS.${PUPPET_USER}=	Puppet configuration management pseudo-user

PLIST_SUBST+=		EGDIR=${EGDIR}
PLIST_VARS+=		sunos

BUILD_DEFS+=		VARBASE
INSTALLATION_DIRS+=	${EGDIR}

.include "../../mk/bsd.prefs.mk"

#PUPPET_GROUP?=		puppet
#PUPPET_USER?=		puppet

.if ${OPSYS} == "SunOS"
INSTALLATION_DIRS+=	lib/svc/method ${EGDIR}/svc
CONF_DIRS+=		${VARBASE}/svc/manifest
CONF_FILES+=		${EGDIR}/svc/puppetd.xml ${VARBASE}/svc/manifest/puppetd.xml
CONF_FILES+=		${EGDIR}/svc/puppetmasterd.xml ${VARBASE}/svc/manifest/puppetmasterd.xml
PLIST.sunos=		yes
.endif

pre-configure:
	cd ${WRKSRC}/bin && ${CHMOD} ${BINMODE} puppet

pre-build:
	cd ${WRKSRC} && \
		${FIND} lib/puppet spec -type f -exec ${CHMOD} -x {} \;
	cd ${WRKSRC} && ${RUBY} -Ilib bin/puppet agent			\
		--confdir=${PKG_SYSCONFDIR:Q} --rundir=${VARBASE:Q}/run	\
		--genconfig |						\
		${SED} -e 's/genconfig = true/# genconfig = false/'	\
		> examples/puppet.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/puppet.conf			\
		${DESTDIR}${PREFIX}/${EGDIR}
.if ${OPSYS} == "SunOS"
	${INSTALL_DATA} ${WRKSRC}/ext/solaris/smf/puppetd.xml		\
		${DESTDIR}${PREFIX}/${EGDIR}/svc
	${INSTALL_DATA} ${WRKSRC}/ext/solaris/smf/puppetmasterd.xml	\
		${DESTDIR}${PREFIX}/${EGDIR}/svc
	${INSTALL_SCRIPT} ${WRKSRC}/ext/solaris/smf/svc-puppetd		\
		${DESTDIR}${PREFIX}/lib/svc/method
	${INSTALL_SCRIPT} ${WRKSRC}/ext/solaris/smf/svc-puppetmasterd	\
		${DESTDIR}${PREFIX}/lib/svc/method
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
