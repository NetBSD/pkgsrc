# $NetBSD: Makefile,v 1.5 1999/12/06 21:09:12 abs Exp $
#

DISTNAME=	nocol-4.2.2beta4
PKGNAME=	nocol-4.2.2b4
CATEGORIES=	net
MASTER_SITES= 	ftp://ftp.navya.com/pub/vikas/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.netplex-tech.com/software/nocol/

USE_PERL=	yes

INSTALL_TARGET=	install root

post-patch:
	@(hostname=`/bin/hostname`;					\
	dir="";								\
	for d in /usr/bin /usr/sbin `${ECHO} $$PATH | tr ':' ' '`; do	\
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

do-configure:
	(cd ${WRKSRC}; ./Configure < answers)

.include "../../mk/bsd.pkg.mk"
