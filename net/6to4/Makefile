# $NetBSD: Makefile,v 1.12 2003/07/17 22:50:55 grant Exp $
#

DISTNAME=		6to4-1.3
WRKSRC=			${WRKDIR}
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/packages/net/6to4/files/6to4.html
COMMENT=		Enables 6to4 IPv6 automatic tunnels

USE_PERL5=		YES

# This pkg doesn't regard USE_INET6 (leave this comment for README-IPv6.html!)
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

do-build:
.for FILE in 6to4
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|g'	\
		< ${FILESDIR}/${FILE}	 		\
		> ${WRKSRC}/${FILE}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/6to4 ${PREFIX}/sbin/6to4
	${INSTALL_MAN} ${FILESDIR}/6to4.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${FILESDIR}/6to4.conf ${PREFIX}/etc/6to4.conf-example
	${INSTALL_DATA} ${FILESDIR}/6to4.html ${PREFIX}/share/doc/6to4.html

.include "../../mk/bsd.pkg.mk"
