# $NetBSD: Makefile,v 1.8 2001/10/25 20:40:07 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1996/11/18 11:22:35 asami Exp
#

DISTNAME=		bcc
PKGNAME=		bcc-95.3.12
CATEGORIES=		devel

MAINTAINER=		tsarna@netbsd.org
COMMENT=		Bruce Evans' C compiler (with as and ld); can do 16-bit code

NOT_FOR_PLATFORM=	*-*-alpha	# Severe LP64 problems

MANCOMPRESSED_IF_MANZ=	yes

do-configure:
	${RM} -f ${WRKSRC}/as/typeconv.o
	${MV} ${WRKSRC}/bcc ${WRKSRC}/bcc-cc1
	${MKDIR} ${WRKSRC}/bcc
	${CP} -p ${FILESDIR}/Makefile.bcc ${WRKSRC}/bcc/Makefile
	${CP} -p ${FILESDIR}/ld86.1 ${WRKSRC}/ld/
	${CP} -p ${FILESDIR}/as86.1 ${WRKSRC}/as/
	${CP} -p ${FILESDIR}/bcc.1 ${WRKSRC}/bcc/
	${CP} -p ${FILESDIR}/bcc-cc1.1 ${WRKSRC}/bcc-cc1/

.include "../../mk/bsd.pkg.mk"
