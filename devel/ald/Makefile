# $NetBSD: Makefile,v 1.14 2011/03/01 09:06:41 obache Exp $
#

DISTNAME=	ald-0.1.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ald/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ald.sourceforge.net/
COMMENT=	Very nice x86 assembly-level debugger
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	*-*-i386

GNU_CONFIGURE=	YES

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
