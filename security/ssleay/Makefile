# $NetBSD: Makefile,v 1.10 1998/10/02 22:02:25 tv Exp $
# FreeBSD: Makefile,v 1.20 1998/08/27 16:38:02 markm Exp
#
#  Note that the config file goes in ${PREFIX}/lib; this cannot easily
#  be changed to etc without modifing a bunch of code on the software
#  itself, due to certain assumptions it makes. [cjs]
#

DISTNAME=		SSLeay-0.9.0b
CATEGORIES=		devel security
MASTER_SITES=		ftp://psych.psy.uq.oz.au/pub/Crypto/SSL/

MAINTAINER=		explorer@netbsd.org
HOMEPAGE=		http://www.psy.uq.oz.au/~ftp/Crypto/

ONLY_FOR_ARCHS=		alpha arm32 i386 m68k mips mipse[bl] ns32k powerpc \
			sparc sparc64 vax

USE_PERL5=		yes

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	util/NetBSD.sh
CONFIGURE_ARGS=		${MACHINE_ARCH}
CONFIGURE_ENV+=		PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}

PLIST_SRC=	${PKGDIR}/PLIST

.include "../../mk/bsd.prefs.mk"

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
DEPENDS=		rsaref-2.0:../../security/rsaref
CONFIGURE_ENV+=		USE_RSAREF_DEF=-DRSAref
MAKE_ENV+=		USE_RSAREF=YES
PLIST_SRC+=		${PKGDIR}/PLIST.rsaref2
.endif

fetch-depends:
.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
	@${ECHO}
	@${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
	@${ECHO} in order to build this package.  People with no RSA
	@${ECHO} license MUST set this variable to YES.  Users outside
	@${ECHO} the USA MUST set this variable to NO.  RSA licensees may
	@${ECHO} choose -- NO is faster.
	@${FALSE}
.endif

post-extract:
	@${CP} -f ${FILESDIR}/NetBSD.sh ${WRKSRC}/util/
	@chmod +x ${WRKSRC}/util/NetBSD.sh

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
post-configure:
	@${CP} ${WRKSRC}/rsaref/rsaref.h ${WRKSRC}/include/rsaref.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SSLeay
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/SSLeay
.endif

.include  "../../mk/bsd.pkg.mk"
