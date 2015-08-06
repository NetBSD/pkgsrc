# $NetBSD: Makefile,v 1.41 2015/08/06 11:13:32 wiz Exp $

DISTNAME=	psiconv-0.9.9
CATEGORIES=	converters
MASTER_SITES=	http://www.frodo.looijaard.name/system/files/software/psiconv/

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
