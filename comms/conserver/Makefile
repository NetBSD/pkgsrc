# $NetBSD: Makefile,v 1.1.1.1 2002/05/09 16:35:25 hubertf Exp $
# FreeBSD Id: ports/comms/conserver-com/Makefile,v 1.1 2001/12/09 14:40:12 kur iyama Exp

DISTNAME=      conserver-7.1.3
CATEGORIES=    comms
MASTER_SITES=  ftp://ftp.conserver.com/conserver/

MAINTAINER=    packages@netbsd.org
HOMEPAGE=      http://www.conserver.com/
COMMENT=       Application that allows multiple users to watch serial consoles

GNU_CONFIGURE= YES
CONFIGURE_ARGS=		--with-master=${DEFAULTHOST} \
			--with-port=${DEFAULTPORT} \
			--with-libwrap

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL

DEFAULTPORT?=  782
DEFAULTHOST?=  localhost
RCD_SCRIPTS=   conserver

pre-install:
	for script in ${RCD_SCRIPTS}; do                        \
		${SED} ${FILES_SUBST_SED} ${FILESDIR}/$${script}.sh \
		>${WRKDIR}/$${script};                          \
	done

post-install:
	for script in ${RCD_SCRIPTS} ; do                       \
		${INSTALL_SCRIPT} ${WRKDIR}/$${script}          \
		${PREFIX}/etc/rc.d/$${script};                  \
	done
	${MKDIR} /var/console

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
