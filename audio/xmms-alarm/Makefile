# $NetBSD: Makefile,v 1.1.1.1 2003/08/12 07:10:07 wiz Exp $
#

DISTNAME=		xmms-alarm-0.3.3
CATEGORIES=		audio
MASTER_SITES=		http://www.snika.uklinux.net/xmms-alarm/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.snika.uklinux.net/index.php?show=xmms-alarm
COMMENT=		Plugin which allows XMMS to be used as an alarm clock

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
