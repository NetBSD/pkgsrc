# $NetBSD: Makefile,v 1.32 2003/09/23 21:39:46 abs Exp $
#

DISTNAME=	hylafax-4.1.7
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/ \
		ftp://ftp.leo.org/pub/comp/os/unix/networking/fax/hylafax/source/

MAINTAINER=	hallmanns@surfeu.de
HOMEPAGE=	http://www.hylafax.org/
COMMENT=	Telecommunication and fax server system

DEPENDS+=	tiff-[0-9]*:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	mawk>=1.2.2:../../lang/mawk

DIST_SUBDIR=	hylafax

CONFLICTS=	mgetty-[0-9]*

USE_PKGINSTALL=	yes

FAXUSER?=	uucp
FAXGROUP?=	dialer
RCD_SCRIPTS=	hylafax

HAS_CONFIGURE=	YES
CONFIGURE_ENV=	PREFIX="${PREFIX}" FAXUID="${FAXUSER}" FAXGID="${FAXGROUP}"
CONFIGURE_ARGS=	--with-MAKE=${MAKE_PROGRAM} --with-INSTALL="" --nointeractive
MANCOMPRESSED=	yes

SUID_EXES=	${PREFIX}/libexec/faxgetty ${PREFIX}/sbin/faxq \
		${PREFIX}/bin/faxrm ${PREFIX}/bin/faxalter

post-install:
	${CHOWN} ${FAXUSER} ${SUID_EXES}
	${CHMOD} 4555 ${SUID_EXES}

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
