# $NetBSD: Makefile,v 1.40 2014/10/07 16:47:20 adam Exp $

DISTNAME=	psiconv-0.9.7
PKGREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	http://software.frodo.looijaard.name/psiconv/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.frodo.looijaard.name/psiconv/
COMMENT=	PSION 5 file format data conversion utilities

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-imagemagick
CONFIGURE_ARGS+=	--with-etcdir=${EGDIR:Q}

EGDIR=		${PREFIX}/share/examples/psiconv
CONF_FILES+=	${EGDIR}/psiconv.conf ${PKG_SYSCONFDIR}/psiconv.conf
CONF_FILES+=	${EGDIR}/psiconv.conf.eg ${PKG_SYSCONFDIR}/psiconv.conf.eg

.include "../../mk/bsd.pkg.mk"
