# $NetBSD: Makefile,v 1.7 2011/11/08 15:42:27 taca Exp $
#

DISTNAME=	dnsdoctor-1.0.1
CATEGORIES=	net
MASTER_SITES=	http://www.dnsdoctor.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dnsdoctor.org/
COMMENT=	DNS zones misconfigurations or inconsistencies diagnostic tool
LICENSE=	gnu-gpl-v2

DEPENDS+=	ruby${RUBY_VER}-base>=${RUBY_VERSION}:../../lang/ruby${RUBY_VER}-base

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/dnsdoctor

# Config name conflict, need many changes.
RUBY_VERSION_SUPPORTED=	18
NO_BUILD=	yes

DDOC_HTML_PATH?=	/dnsdoctor
EGDIR=			share/examples
DDOCEGDIR=		${EGDIR}/dnsdoctor
# No we don't want to use PKG_SYSCONFSUBDIR
DDOCCONFDIR=		${PKG_SYSCONFDIR}/dnsdoctor
OWN_DIRS=		${PKG_SYSCONFDIR}/dnsdoctor

RUBY_ENCODING_ARG=	-Ku
REPLACE_RUBY+=		contrib/dig.rb dnsdoctor/zc.rb

DDOC_INSTALLER_RB_ARGS+=	-DRUBY=${RUBY:Q}
DDOC_INSTALLER_RB_ARGS+=	-DPREFIX=${PREFIX:Q}
DDOC_INSTALLER_RB_ARGS+=	-DEGDIR=${PREFIX:Q}/${EGDIR:Q}
DDOC_INSTALLER_RB_ARGS+=	-DETCDIR=${PKG_SYSCONFDIR:Q}
DDOC_INSTALLER_RB_ARGS+=	-DHTML_PATH=${DDOC_HTML_PATH:Q}

CONF_FILES+=	${DDOCEGDIR}/afnic.profile ${DDOCCONFDIR}/afnic.profile
CONF_FILES+=	${DDOCEGDIR}/de.profile ${DDOCCONFDIR}/de.profile
CONF_FILES+=	${DDOCEGDIR}/default.profile ${DDOCCONFDIR}/default.profile
CONF_FILES+=	${DDOCEGDIR}/reverse.profile ${DDOCCONFDIR}/reverse.profile
CONF_FILES+=	${DDOCEGDIR}/rootservers ${DDOCCONFDIR}/rootservers
CONF_FILES+=	${DDOCEGDIR}/dnsdoctor.conf ${DDOCCONFDIR}/dnsdoctor.conf

MAKE_ENV+=		DESTDIR=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
	${RUBY} ./installer.rb	${DDOC_INSTALLER_RB_ARGS} configure configinfo

do-install:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${RUBY} ${RUBY_ENCODING_ARG} ./installer.rb \
		${DDOC_INSTALLER_RB_ARGS} all
	${INSTALL_DATA} ${WRKSRC}/www/dnsdoctor.conf \
		${DESTDIR}${PREFIX}/${DDOCEGDIR}/httpd-dnsdoctor.conf

.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
