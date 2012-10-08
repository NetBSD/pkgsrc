# $NetBSD: Makefile,v 1.15 2012/10/08 12:19:35 asau Exp $

DISTNAME=		xmailwatcher
PKGNAME=		${DISTNAME}-1.6
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://www.dcs.ed.ac.uk/home/gdmr/X11/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=	Mailbox checker which displays sender and subject lines of mails

USE_IMAKE=		yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
