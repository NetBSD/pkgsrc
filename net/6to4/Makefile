# $NetBSD: Makefile,v 1.1.1.1 2001/02/11 05:24:29 hubertf Exp $
#

DISTNAME=		6to4-1.0
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.netbsd.org/packages/net/6to4/files/6to4.html

USE_PERL5=		YES
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

do-build:
.for FILE in 6to4
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|g'	\
		< ${FILESDIR}/${FILE}	 		\
		> ${WRKSRC}/${FILE}
.endfor
	${SED} \
		-e 's,@PREFIX@,${PREFIX},' \
		<${PKGDIR}/DEINSTALL  >${DEINSTALL_FILE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/6to4 ${PREFIX}/sbin/6to4
	${INSTALL_MAN} ${FILESDIR}/6to4.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${FILESDIR}/6to4.conf ${PREFIX}/etc/6to4.conf-example
	${INSTALL_DATA} ${FILESDIR}/6to4.html ${PREFIX}/share/doc/6to4.html

.include "../../mk/bsd.pkg.mk"
