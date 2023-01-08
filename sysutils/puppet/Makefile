# $NetBSD: Makefile,v 1.59.2.1 2023/01/08 15:57:24 bsiegert Exp $

DISTNAME=		puppet-7.21.0
PKGREVISION=		2
CATEGORIES=		sysutils

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://puppet.com/
COMMENT=		Configuration management framework written in Ruby
LICENSE=		apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-facter>=4.2.0:../../sysutils/ruby-facter
DEPENDS+=	${RUBY_PKGPREFIX}-hiera>=3.2.1:../../databases/ruby-hiera
DEPENDS+=	${RUBY_PKGPREFIX}-semantic_puppet>=1.0<2:../../devel/ruby-semantic_puppet
DEPENDS+=	${RUBY_PKGPREFIX}-fast_gettext>=1.1:../../devel/ruby-fast_gettext
DEPENDS+=	${RUBY_PKGPREFIX}-locale>=2.1<3:../../devel/ruby-locale
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.10<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-puppet-resource_api>=1.5<2:../../sysutils/ruby-puppet-resource_api
DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0<2:../../devel/ruby-concurrent-ruby
DEPENDS+=	${RUBY_PKGPREFIX}-deep_merge>=1.0<2:../../devel/ruby-deep_merge
DEPENDS+=	${RUBY_PKGPREFIX}-scanf>=1.0.0<2:../../devel/ruby-scanf

RUBYGEM_OPTIONS+=	--format-executable
RUBYGEM_MANPAGES=	yes
USE_LANGUAGES=		# none

PKG_SYSCONFSUBDIR=	puppet
RCD_SCRIPTS=		puppetd puppetmasterd

SMF_SRCDIR=		${WRKSRC}/ext/solaris/smf
SMF_MANIFEST=		puppet.xml
SMF_METHODS=		puppet
SMF_METHOD_SRC.puppet=	${SMF_SRCDIR}/puppet
SMF_NAME=		puppet

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
SUBST_FILES.prefix+=	man/man5/puppet.conf.5
SUBST_FILES.prefix+=	man/man8/puppet-apply.8
SUBST_FILES.prefix+=	man/man8/puppet-module.8
SUBST_FILES.prefix+=	man/man8/puppet-parser.8
SUBST_FILES.prefix+=	spec/unit/util/run_mode_spec.rb
SUBST_FILES.prefix+=	spec/unit/util/selinux_spec.rb
SUBST_SED.prefix=	-e "s|/etc/puppet|${PKG_SYSCONFDIR}|g"

SUBST_CLASSES+=		smf
SUBST_STAGE.smf=	pre-configure
SUBST_FILES.smf+=	ext/solaris/smf/puppet
SUBST_FILES.smf+=	ext/solaris/smf/puppet.xml
SUBST_SED.smf=		-e "s,/etc/puppetlabs/puppet,${PKG_SYSCONFDIR},g"
SUBST_SED.smf+=		-e "s,/opt/puppetlabs/bin/puppet,${PREFIX}/bin/puppet${RUBY_SUFFIX},g"
SUBST_SED.smf+=		-e "s,network/puppet,${SMF_PREFIX}/puppet,g"

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

BUILD_DEFS+=		VARBASE
INSTALLATION_DIRS+=	${EGDIR}

.include "../../mk/bsd.prefs.mk"

#PUPPET_GROUP?=		puppet
#PUPPET_USER?=		puppet

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

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
