# $NetBSD: Makefile,v 1.9 2009/02/10 17:22:20 joerg Exp $

DISTNAME=	newmail-1.0.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ugh.net.au/pub/unix/newmail/

MAINTAINER=	andrew@ugh.net.au
COMMENT=	Program to check multiple local mailboxes for new mail

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/newmail

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
