# $NetBSD: Makefile,v 1.12 1999/03/06 21:24:43 kim Exp $
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
MIRROR_DISTFILE= no
NO_WRKSUBDIR=	yes

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

PLIST_SRC=	${PKGDIR}/PLIST ${WRKSRC}/PLIST.man

post-install:
	@${MKDIR} ${PREFIX}/share/examples/kermit
	${INSTALL_DATA} ${FILESDIR}/dot.kermrc ${PREFIX}/share/examples/kermit
	@${CP} /dev/null ${WRKDIR}/PLIST.man
	@for i in ${MANINSTALL} x; do \
	    case $$i in \
	    catinstall) echo man/cat1/kermit.0 >> ${WRKDIR}/PLIST.man;; \
	    maninstall) echo man/man1/kermit.1 >> ${WRKDIR}/PLIST.man;; \
	    esac; \
	done

.include "../../mk/bsd.pkg.mk"
