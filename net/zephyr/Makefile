# $NetBSD: Makefile,v 1.18 2001/01/26 05:21:47 hubertf Exp $
#

DISTNAME=	zephyr-2.0.4
CATEGORIES=	net athena
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/dist/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://web.mit.edu/olh/Zephyr/index.html

.include "../../mk/bsd.prefs.mk"

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=	yes
CONFIGURE_ARGS+="--with-krb4"
CONFIGURE_ENV+=	CPPFLAGS=-I/usr/include/kerberosIV
.else
CONFIGURE_ARGS+="--without-krb4"
.endif

USE_X11=	yes
GNU_CONFIGURE=	yes

ZEPHYR_RCDIR=	${PREFIX}/etc/rc.d
ZEPHYR_DOCDIR=	${PREFIX}/share/doc/zephyr
ZEPHYR_DOCS=	INSTALL NOTES OPERATING README USING

post-install:
	${MKDIR} ${ZEPHYR_RCDIR}
	${SED} -e 's|@prefix@|'${PREFIX}'|g' < ${FILESDIR}/zhm.sh > ${WRKDIR}/zhm.sh
	${INSTALL_SCRIPT} ${WRKDIR}/zhm.sh ${ZEPHYR_RCDIR}/zhm
	${MKDIR} ${ZEPHYR_DOCDIR}
	for file in ${ZEPHYR_DOCS} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$file ${ZEPHYR_DOCDIR} ; \
	    done

.include "../../mk/bsd.pkg.mk"
