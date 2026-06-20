# $NetBSD: Makefile,v 1.17 2026/06/20 10:57:44 nia Exp $

DISTNAME=		xmailwatcher
PKGNAME=		${DISTNAME}-1.6
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://www.dcs.ed.ac.uk/home/gdmr/X11/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Mailbox checker which displays sender and subject lines of mails

USE_IMAKE=		yes

# This is old code that uses K&R style function definitions.
# Since an evolving C standard is likely to cause compatibility
# problems with it, we force a "known working" standard. In this
# case, the minimum bootstrap requirement, and not in strict standard
# mode to ensure no APIs are hidden.
FORCE_C_STD=		gnu99

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
