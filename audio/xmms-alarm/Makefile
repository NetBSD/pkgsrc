# $NetBSD: Makefile,v 1.5 2004/11/26 21:04:59 snj Exp $
#

DISTNAME=		xmms-alarm-0.3.6
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
