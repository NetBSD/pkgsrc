# $NetBSD: Makefile,v 1.5 1998/09/17 12:34:28 frueauf Exp $
# FreeBSD: Makefile,v 1.20 1998/08/27 16:38:02 markm Exp
#

DISTNAME=		SSLeay-0.9.0b
CATEGORIES=		devel security
MASTER_SITES=		ftp://psych.psy.uq.oz.au/pub/Crypto/SSL/

MAINTAINER=		explorer@netbsd.org
HOMEPAGE=		http://www.psy.uq.oz.au/~ftp/Crypto/

ONLY_FOR_ARCHS=		i386 sparc m68k alpha
DEPENDS=		rsaref-2.0:../../security/rsaref

USE_PERL5=		yes

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	util/NetBSD.sh
CONFIGURE_ARGS=		${MACHINE_ARCH}

post-extract:
	${SED} -e 's|@@@PREFIX@@@|${PREFIX}|g' < ${FILESDIR}/NetBSD.sh \
		> ${WRKSRC}/util/NetBSD.sh

post-configure:
	${CP} ${WRKSRC}/rsaref/rsaref.h ${WRKSRC}/include/rsaref.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SSLeay
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/SSLeay
.endif

.include  "../../mk/bsd.pkg.mk"
