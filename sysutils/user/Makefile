# $NetBSD: Makefile,v 1.12 2002/12/07 02:39:05 schmonz Exp $
#

# Note to package maintainers:
# To update the distfile of this pkg, cd to /usr/src/usr.sbin,
# "tar pzvcf user-`date +%Y%m%d`.tar.gz user" and upload that
# file to ${MASTER_SITE_LOCAL}.
DISTNAME=		user-20000509
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		Solaris-compatible {user,group}{add,del,mod} commands

WRKSRC=			${WRKDIR}/user

ONLY_FOR_PLATFORM=	NetBSD-*-* # already in Solaris base system

.if exists(/usr/sbin/user)
PKG_SKIP_REASON=	"${PKGNAME} is part of your ${OPSYS} distribution"
.endif

NO_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

PLIST_SRC=		${WRKDIR}/PLIST

MAKE_ENV+=		BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man \
			FILESDIR=${PREFIX}/share/examples/usermgmt

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
