# $NetBSD: Makefile,v 1.1.1.1 1999/08/11 06:04:26 rh Exp $
#

DISTNAME=	hylafax-4.1beta1
PKGNAME=	hylafax-4.1b1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/hylafax/source/BETA/ \
		ftp://ftp.leo.org/pub/comp/os/unix/networking/fax/hylafax/source/BETA/ \
		ftp://ftp.sisis.de/pub/hylafax/source/BETA/ \
		ftp://ftp.uni-bremen.de/pub/mirrors/ftp.hylafax.org/pub/hylafax/source/BETA/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.hylafax.org/

DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	mawk-1.2.2:../../lang/mawk
DEPENDS+=	ghostscript-5.50:../../print/ghostscript5

CONFLICTS=	mgetty-*

FAXUSER?=	uucp
FAXGROUP?=	dialer

USE_GMAKE=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ENV=	PREFIX="${PREFIX}" FAXUID="${FAXUSER}" FAXGID="${FAXGROUP}"
CONFIGURE_ARGS=	--with-MAKE=${MAKE_PROGRAM} --with-INSTALL=""
MANCOMPRESSED=	yes

SUID_EXES=	${PREFIX}/libexec/faxgetty ${PREFIX}/sbin/faxq \
		${PREFIX}/bin/faxrm ${PREFIX}/bin/faxalter

post-install:
	${CHOWN} ${FAXUSER} ${SUID_EXES}
	${CHMOD} 4555 ${SUID_EXES}

.include "../../mk/bsd.pkg.mk"
