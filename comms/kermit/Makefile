# $NetBSD: Makefile,v 1.16 1999/11/23 16:26:12 hubertf Exp $
# $FreeBSD Id: Makefile,v 1.17 1997/11/26 23:16:51 jseger Exp
#

DISTNAME=	cku192src
PKGNAME=        kermit-6.0.192
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
		ftp://ftp.th-darmstadt.de/pub/networking/kermit/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.columbia.edu/kermit/

RESTRICTED=	"'No redistribution' copyright"
NO_CDROM=	${RESTRICTED}
MIRROR_DISTFILE= no
NO_WRKSUBDIR=	yes

MANCOMPRESSED_IF_MANZ=	yes

PLIST_SRC=	${WRKDIR}/PLIST

post-install:
	@${MKDIR} ${PREFIX}/share/examples/kermit
	${INSTALL_DATA} ${FILESDIR}/dot.kermrc ${PREFIX}/share/examples/kermit
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@for OPT in ${MANINSTALL} x; do \
	  case $$OPT in \
	    catinstall) ${ECHO} man/cat1/kermit.0 >>${PLIST_SRC};; \
	    maninstall) ${ECHO} man/man1/kermit.1 >>${PLIST_SRC};; \
	  esac; \
	done

.include "../../mk/bsd.pkg.mk"
