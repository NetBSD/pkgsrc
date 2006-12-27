# $NetBSD: Makefile,v 1.9 2006/12/27 13:37:39 joerg Exp $

DISTNAME=		xmailwatcher
PKGNAME=		${DISTNAME}-1.6
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.dcs.ed.ac.uk/pub/X11/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT= 		Mailbox checker which displays sender and subject lines of mails

USE_IMAKE=		yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
