# $NetBSD: Makefile,v 1.10 2000/08/31 18:02:22 skrll Exp $
#

DISTNAME=		nocol-4.3.1
PKGNAME=		nocol-4.3.1nb1
CATEGORIES=		net
MASTER_SITES= 		http://www.netplex-tech.com/software/nocol/downloads/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netplex-tech.com/software/nocol/

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	< ${FILESDIR}/answers

USE_PERL5=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/cmu-snmp/snmp/ltconfig \
			${WRKSRC}/cmu-snmp/snmpapps/ltconfig

INSTALL_TARGET=		install root

post-patch:
	@(hostname=`/bin/hostname`;					\
	dir="";								\
	for d in /usr/bin /usr/sbin `${ECHO} $$PATH | ${TR} ':' ' '`; do \
		if [ -x $$d/host ]; then				\
			dir=$$d;					\
			break;						\
		fi							\
	done;								\
	if [ "X$$dir" = "X" ]; then					\
		${ECHO} "host program not found";			\
		exit 1;							\
	fi;								\
	fqdn=`$$dir/host $$hostname | ${AWK} '{ print $$1; exit }'`;	\
	${SED} -e 's|@prefix@|${PREFIX}|g' -e "s|@FQDN@|$$fqdn|g" 	\
			${FILESDIR}/answers > ${WRKSRC}/answers)

post-install:
	# Ensure webnocol audio and images files are available if needed
	#
	${MKDIR} ${PREFIX}/share/nocol/gifs

	for f in critical.wav error.wav warning.wav ; do		\
	    ${INSTALL_DATA} ${WRKSRC}/webnocol/$$f ${PREFIX}/share/nocol; \
	done

	for f in bluesq.gif critical.jpg empty.gif error.jpg		\
		greensq.gif help.jpg info.jpg redsq.gif warning.jpg	\
		yellowsq.gif ; do					\
	    ${INSTALL_DATA} ${WRKSRC}/webnocol/gifs/$$f			\
			    ${PREFIX}/share/nocol/gifs;			\
	done

.include "../../mk/bsd.pkg.mk"
