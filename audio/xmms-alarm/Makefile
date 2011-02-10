# $NetBSD: Makefile,v 1.14 2011/02/10 21:51:37 zafer Exp $
#

DISTNAME=		xmms-alarm-0.3.7
CATEGORIES=		audio
MASTER_SITES=		http://distfiles.aydogan.net/audio/
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
