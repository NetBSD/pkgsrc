# $NetBSD: Makefile,v 1.12 2005/03/24 21:12:52 wiz Exp $

DISTNAME=		bcc
PKGNAME=		bcc-95.3.12
CATEGORIES=		devel lang

MAINTAINER=		tsarna@NetBSD.org
COMMENT=		Bruce Evans' C compiler (with as and ld); can do 16-bit code

NOT_FOR_PLATFORM=	*-*-alpha	# Severe LP64 problems

MANCOMPRESSED_IF_MANZ=	yes

do-configure:
	${RM} -f ${WRKSRC}/as/typeconv.o
	${MV} ${WRKSRC}/bcc ${WRKSRC}/bcc-cc1
	${MKDIR} ${WRKSRC}/bcc
	${CP} ${FILESDIR}/Makefile.bcc ${WRKSRC}/bcc/Makefile
	${CP} ${FILESDIR}/ld86.1 ${WRKSRC}/ld/
	${CP} ${FILESDIR}/as86.1 ${WRKSRC}/as/
	${CP} ${FILESDIR}/bcc.1 ${WRKSRC}/bcc/
	${CP} ${FILESDIR}/bcc-cc1.1 ${WRKSRC}/bcc-cc1/

.include "../../mk/bsd.pkg.mk"
