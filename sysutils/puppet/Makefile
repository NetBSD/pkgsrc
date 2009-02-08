# $NetBSD: Makefile,v 1.4 2009/02/08 23:01:56 tonnerre Exp $

DISTNAME=		puppet-0.24.7
CATEGORIES=		sysutils

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://www.reductivelabs.com/projects/puppet/
MASTER_SITE=		http://reductivelabs.com/downloads/gems/
COMMENT=		Configuration management framework written in Ruby

DEPENDS+=		${RUBY_PKGPREFIX}-facter>=1.3.8:../../sysutils/ruby-facter

GEM_BUILD=		gemspec

PKG_SYSCONFSUBDIR=	puppet
RCD_SCRIPTS=		puppetd puppetmasterd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	lib/puppet/reference/configuration.rb
SUBST_FILES.prefix+=	lib/puppet/defaults.rb spec/unit/util/selinux.rb
SUBST_FILES.prefix+=	bin/puppetrun bin/puppet bin/puppetdoc
SUBST_FILES.prefix+=	ext/puppetstoredconfigclean.rb ext/puppetlast
SUBST_FILES.prefix+=	examples/puppetmasterd.conf man/man8/puppet.8
SUBST_FILES.prefix+=	conf/solaris/smf/puppetd.xml
SUBST_FILES.prefix+=	conf/solaris/smf/puppetmasterd.xml
SUBST_FILES.prefix+=	man/man8/puppetrun.8 man/man8/puppet.conf.8
SUBST_SED.prefix=	-e "s|/etc/puppet|${PKG_SYSCONFDIR}|g"

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/puppet.conf ${PKG_SYSCONFDIR}/puppet.conf

pre-build:
	cd ${WRKSRC} && ${RUBY} -Ilib bin/puppetmasterd			\
		--confdir=${PKG_SYSCONFDIR:Q} --rundir=${VARBASE:Q}/run	\
		--genconfig |						\
		${SED} -e 's/genconfig = true/# genconfig = false/'	\
		> examples/puppet.conf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/puppet.conf		\
		${DESTDIR}${EGDIR}

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
