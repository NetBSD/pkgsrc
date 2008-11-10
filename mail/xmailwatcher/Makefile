# $NetBSD: Makefile,v 1.12 2008/11/10 17:21:37 wiz Exp $

DISTNAME=		xmailwatcher
PKGNAME=		${DISTNAME}-1.6
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://www.dcs.ed.ac.uk/home/gdmr/X11/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=	Mailbox checker which displays sender and subject lines of mails

USE_IMAKE=		yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
