# $NetBSD: Makefile,v 1.10 1998/06/03 13:16:57 agc Exp $
#

DISTNAME=	zephyr-2.0.4
CATEGORIES=	net athena
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/dist/

MAINTAINER=	mycroft@NetBSD.ORG

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/lib/libkrb.a) && (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
CONFIGURE_ARGS+="--with-krb4"
CONFIGURE_ENV+=CPPFLAGS=-I/usr/include/kerberosIV
.endif

GNU_CONFIGURE=	yes
MAN1=		zephyr.1 xzwrite.1 zaway.1 zctl.1 zleave.1 zlocate.1 \
		zmailnotify.1 znol.1 zwgc.1 zwrite.1
MAN3=		com_err.3
MAN8=		syslogd.8 zpopnotify.8 zshutdown_notify.8 zstat.8 \
		zephyrd.8 zhm.8

ZEPHYR_RCDIR=	${PREFIX}/etc/rc.d
ZEPHYR_DOCDIR=	${PREFIX}/share/doc/zephyr
ZEPHYR_DOCS=	INSTALL NOTES OPERATING README USING

post-install:
	${MKDIR} ${ZEPHYR_RCDIR}
	${SED} -e 's|@prefix@|'${PREFIX}'|g' < ${FILESDIR}/zhm.sh > ${WRKDIR}/zhm.sh
	${INSTALL_SCRIPT} ${WRKDIR}/zhm.sh ${ZEPHYR_RCDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${ZEPHYR_DOCDIR}
	for file in ${ZEPHYR_DOCS} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$file ${ZEPHYR_DOCDIR} ; \
	    done
.endif

.include "../../mk/bsd.pkg.mk"
