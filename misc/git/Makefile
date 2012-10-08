# $NetBSD: Makefile,v 1.33 2012/10/08 09:57:22 asau Exp $

DISTNAME=	gnuit-4.9.5
PKGNAME=	${DISTNAME:S/gnuit-/git-/}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hulubei.net/tudor/git/
COMMENT=	GNU Interactive Tools - a file system browser for UNIX systems
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/gnuit
CONFIGURE_ARGS+=	--disable-transition
INFO_FILES=	YES

post-extract:
	${CP} ${WRKSRC}/term/gnuitrc.ansi.in ${WRKSRC}/term/gnuitrc.cons25.in

CHECK_FILES_SKIP+=	lib/charset.alias

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
