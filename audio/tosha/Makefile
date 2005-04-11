# $NetBSD: Makefile,v 1.12 2005/04/11 21:44:57 tv Exp $

DISTNAME=	tosha-0.05
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tu-clausthal.de/pub/unix/audio/

MAINTAINER=	oliver.fromme@heim3.tu-clausthal.de
HOMEPAGE=	http://www.heim3.tu-clausthal.de/~olli/tosha/
COMMENT=	Read CD digital audio data through the SCSI bus

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/libscsi/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
