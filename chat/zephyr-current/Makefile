# $NetBSD: Makefile,v 1.1.1.1 2002/12/30 17:39:26 sommerfeld Exp $
#

DISTNAME=	zephyr-20010518
CATEGORIES=	chat net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://web.mit.edu/olh/Zephyr/index.html
COMMENT=	Project Athena's original Instant Messaging system

WRKSRC=		${WRKDIR}/zephyr
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

# N.B. the following assume NetBSD-only.  
CPPFLAGS+=      -I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=       -lroken -lcrypto -lcom_err -ledit -lcurses
CONFIGURE_ARGS+="--with-krb4"
CONFIGURE_ARGS+="--with-hesiod"
CONFIGURE_ARGS+="--with-ares"

ZEPHYR_RCDIR=	${PREFIX}/etc/rc.d
ZEPHYR_DOCDIR=	${PREFIX}/share/doc/zephyr
ZEPHYR_DOCS=	INSTALL NOTES OPERATING README USING

post-install:
	${INSTALL_DATA_DIR} ${ZEPHYR_RCDIR}
	${SED} -e 's|@prefix@|'${PREFIX}'|g' < ${FILESDIR}/zhm.sh > ${WRKDIR}/zhm.sh
	${INSTALL_SCRIPT} ${WRKDIR}/zhm.sh ${ZEPHYR_RCDIR}/zhm
	${INSTALL_DATA_DIR} ${ZEPHYR_DOCDIR}
	for f in ${ZEPHYR_DOCS} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$f ${ZEPHYR_DOCDIR} ; \
	    done

.include "../../devel/readline/buildlink2.mk"
.include "../../net/hesiod/buildlink2.mk"
.include "../../net/libares/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
