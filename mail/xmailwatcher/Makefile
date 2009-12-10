# $NetBSD: Makefile,v 1.13 2009/12/10 23:50:04 abs Exp $

DISTNAME=		xmailwatcher
PKGNAME=		${DISTNAME}-1.6
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://www.dcs.ed.ac.uk/home/gdmr/X11/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=	Mailbox checker which displays sender and subject lines of mails
PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=		yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
