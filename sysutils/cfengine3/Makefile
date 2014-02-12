# $NetBSD: Makefile,v 1.11 2014/02/12 23:18:38 tron Exp $
#

DISTNAME=	cfengine-3.4.2
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://cfengine.com/source-code/download?file=

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://cfengine.com/pages/community
COMMENT=	Tool for automating system administration
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++ c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fhs
CONFIGURE_ARGS+=	--docdir=${DOCDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}
CONFIGURE_ARGS+=	--with-workdir=${CFENGINE_DIR:Q}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl:Q}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre:Q}

BUILD_DEFS+=		VARBASE CFENGINE_DIR
FILES_SUBST+=		CFENGINE_DIR=${CFENGINE_DIR}

CFENGINE_DIR?=		${VARBASE}/cfengine
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	cfengine

CFILES=			cf-sketch-runfile.cf def.cf promises.cf
CFILES+=		controls/cf_agent.cf controls/cf_execd.cf
CFILES+=		controls/cf_monitord.cf controls/cf_report.cf
CFILES+=		controls/cf_runagent.cf controls/cf_serverd.cf
CFILES+=		libraries/cfengine_stdlib.cf services/init_msg.cf

.for file in ${CFILES}
CONF_FILES+=		${EGDIR}/CoreBase/${file} ${PKG_SYSCONFDIR}/${file}
.endfor

RCD_SCRIPTS=		cfserverd cfexecd cfmonitord

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${PKG_SYSCONFDIR} docdir=${DOCDIR} examplesdir=${EGDIR} masterfilesdir=${EGDIR}/CoreBase projlibdir=${PREFIX}/lib

MAKE_DIRS=		${CFENGINE_DIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/controls ${PKG_SYSCONFDIR}/libraries
MAKE_DIRS+=		${PKG_SYSCONFDIR}/services

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
