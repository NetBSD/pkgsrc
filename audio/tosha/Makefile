# $NetBSD: Makefile,v 1.9 2005/02/14 08:19:33 uebayasi Exp $
# FreeBSD Id: Makefile,v 1.2 1997/05/25 08:58:43 andreas Exp
#

DISTNAME=	tosha-0.05
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tu-clausthal.de/pub/unix/audio/

MAINTAINER=	oliver.fromme@heim3.tu-clausthal.de
HOMEPAGE=	http://www.heim3.tu-clausthal.de/~olli/tosha/
COMMENT=	Read CD digital audio data through the SCSI bus

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""

INSTALLATION_DIRS=	bin/man/man1

.include "../../devel/libscsi/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
