# $NetBSD: Makefile,v 1.2 2000/06/01 11:23:33 rh Exp $
#

DISTNAME=	librep-0.7
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dcs.warwick.ac.uk/people/John.Harper/librep/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dcs.warwick.ac.uk/~john/sw/librep.html

ONLY_FOR_PLATFORM=	SunOS-*-*	# only for Solaris, at the moment

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PKGLIBTOOL=	yes

#INFO_FILES=	librep.info

PLIST_SRC=	${WRKDIR}/PLIST-src

post-install:
	case ${OPSYS} in						\
	NetBSD)	platform=""; os="netbsd1" ;;				\
	SunOS)	platform="sun"; os="solaris2" ;;			\
	esac;								\
	${SED} -e 's|@PLATFORM@|'$$platform'|g' -e 's|@OS@|'$$os'|g'	\
			${PKGDIR}/PLIST > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
