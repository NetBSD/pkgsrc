# $NetBSD: Makefile,v 1.8 1998/09/30 20:08:21 cjs Exp $
# FreeBSD: Makefile,v 1.20 1998/08/27 16:38:02 markm Exp
#

DISTNAME=		SSLeay-0.9.0b
CATEGORIES=		devel security
MASTER_SITES=		ftp://psych.psy.uq.oz.au/pub/Crypto/SSL/

MAINTAINER=		explorer@netbsd.org
HOMEPAGE=		http://www.psy.uq.oz.au/~ftp/Crypto/

ONLY_FOR_ARCHS=		i386 sparc m68k alpha

USE_PERL5=		yes

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	util/NetBSD.sh
CONFIGURE_ARGS=		${MACHINE_ARCH}

PLIST_SRC=	${PKGDIR}/PLIST
.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
PLIST_SRC+=	${PKGDIR}/PLIST.rsaref2
.endif

.include "../../mk/bsd.prefs.mk"

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
DEPENDS=		rsaref-2.0:../../security/rsaref
.endif

fetch-depends:
.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
	@${ECHO}
	@${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
	@${ECHO} in order to build this package.  People with no RSA
	@${ECHO} license MUST set this variable to YES.  Users outside
	@${ECHO} the USA MUST set this variable to NO.  RSA licensees may
	@${ECHO} choose -- NO is faster.
	@${ECHO}
	@${ECHO} You may also want to set DONT_USE_IDEA to YES if this program
	@${ECHO} will be used for a commercial purpose.  There are other
	@${ECHO} configure options\; look at the pkg Makefile for more info.
	@${FALSE}
.endif

post-extract:
	${SED} -e 's|@@@PREFIX@@@|${PREFIX}|g' < ${FILESDIR}/NetBSD.sh \
		> ${WRKSRC}/util/NetBSD.sh
	chmod 755 ${WRKSRC}/util/NetBSD.sh

post-patch:
	@${CP} ${WRKSRC}/Configure ${WRKSRC}/foo
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' <${WRKSRC}/foo> ${WRKSRC}/Configure
	@${RM} -f ${WRKSRC}/foo

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
post-configure:
	patch -d ${WRKSRC} <files/patch-rsaref-1
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' <files/patch-rsaref-2 |\
	    patch -d ${WRKSRC}
	${CP} ${WRKSRC}/rsaref/rsaref.h ${WRKSRC}/include/rsaref.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SSLeay
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/SSLeay
.endif

.include  "../../mk/bsd.pkg.mk"
