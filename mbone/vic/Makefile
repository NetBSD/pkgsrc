# $NetBSD: Makefile,v 1.25 2003/10/18 13:17:41 cjep Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/11 03:54:53 fenner Exp
#

DISTNAME=	vicsrc-2.8
PKGNAME=	${DISTNAME:S/src//}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	mbone tk
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-1.[6-9]*)
PATCH_SITES=    ftp://tink.ims.ac.jp/pub/NetBSD/vic/
PATCHFILES=     vic-2.8_ov511p0.diff.gz
.endif

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www-nrg.ee.lbl.gov/vic/
COMMENT=	MBONE video conferencing tool

DEPENDS+=	tk>=8.3.2:../../x11/tk

GNU_CONFIGURE=	yes
USE_X11=	yes

CONFIGURE_ARGS+=	--with-tcl=${PREFIX} --with-tk=${PREFIX}

.include "../../mk/bsd.pkg.mk"
