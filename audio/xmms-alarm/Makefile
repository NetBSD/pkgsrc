# $NetBSD: Makefile,v 1.6 2005/04/11 21:44:58 tv Exp $
#

DISTNAME=		xmms-alarm-0.3.6
CATEGORIES=		audio
MASTER_SITES=		http://www.snika.uklinux.net/xmms-alarm/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.snika.uklinux.net/index.php?show=xmms-alarm
COMMENT=		Plugin which allows XMMS to be used as an alarm clock

USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
