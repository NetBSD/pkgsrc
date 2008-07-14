# $NetBSD: Makefile,v 1.13 2008/07/14 12:55:58 joerg Exp $
#

DISTNAME=		xmms-alarm-0.3.7
CATEGORIES=		audio
MASTER_SITES=		http://www.snika.uklinux.net/xmms-alarm/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.snika.uklinux.net/index.php?show=xmms-alarm
COMMENT=		Plugin which allows XMMS to be used as an alarm clock

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
