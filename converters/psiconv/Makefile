# $NetBSD: Makefile,v 1.29 2005/04/11 21:45:09 tv Exp $

DISTNAME=	psiconv-0.9.6
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://huizen.dds.nl/~frodol/psiconv/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://huizen.dds.nl/~frodol/psiconv/
COMMENT=	PSION 5 file format data conversion utilities

USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-imagemagick
CONFIGURE_ARGS+=	--with-etcdir=${EGDIR}

EGDIR=		${PREFIX}/share/examples/psiconv
CONF_FILES+=	${EGDIR}/psiconv.conf ${PKG_SYSCONFDIR}/psiconv.conf
CONF_FILES+=	${EGDIR}/psiconv.conf.eg ${PKG_SYSCONFDIR}/psiconv.conf.eg

.include "../../mk/bsd.pkg.mk"
