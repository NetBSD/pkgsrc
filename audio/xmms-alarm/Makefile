# $NetBSD: Makefile,v 1.3 2004/03/07 22:52:41 snj Exp $
#

DISTNAME=		xmms-alarm-0.3.3
CATEGORIES=		audio
MASTER_SITES=		http://www.snika.uklinux.net/xmms-alarm/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.snika.uklinux.net/index.php?show=xmms-alarm
COMMENT=		Plugin which allows XMMS to be used as an alarm clock

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
