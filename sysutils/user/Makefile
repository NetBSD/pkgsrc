# $NetBSD: Makefile,v 1.15 2003/09/15 16:27:56 jmmv Exp $
#

# Note to package maintainers:
# To update the distfile of this pkg, cd to /usr/src/usr.sbin,
# "tar pzvcf user-`date +%Y%m%d`.tar.gz user" and upload that
# file to ${MASTER_SITE_LOCAL}.
DISTNAME=		user-20000509
WRKSRC=			${WRKDIR}/user
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Solaris-compatible {user,group}{add,del,mod} commands

ONLY_FOR_PLATFORM=	NetBSD-*-* # already in Solaris base system

.if exists(/usr/sbin/user)
PKG_SKIP_REASON=	"${PKGNAME} is part of your ${OPSYS} distribution"
.endif

NO_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

PLIST_SRC=		${WRKDIR}/PLIST

MAKE_ENV+=		BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man \
			FILESDIR=${PREFIX}/share/examples/usermgmt

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MANINSTALL

pre-install:
			${INSTALL_DATA_DIR} ${PREFIX}/share/examples/usermgmt

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@for OPT in ${MANINSTALL} broken-solaris-needs-this; do \
	  case $$OPT in \
	    catinstall|maninstall) \
		${CAT} ${PKGDIR}/PLIST.$$OPT >>${PLIST_SRC}; \
		;; \
	  esac; \
	done

.include "../../mk/bsd.pkg.mk"
