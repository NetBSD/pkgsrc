# $NetBSD: Makefile,v 1.15 2001/10/26 11:35:03 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1996/12/01 01:22:54 obrien Exp 
#

DISTNAME=	mirror-2.9
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	packages@netbsd.org
COMMENT=	Mirror packages on remote sites

USE_PERL5=	# defined

WRKSRC=		${WRKDIR}
MAKEFILE=	makefile
SCRIPTS_ENV+=	PERL5=${PERL5}

REPLACE_PERL=	do_unlinks.pl mirror.pl mm.pl pkgs_to_mmin.pl

do-configure:
	cd ${WRKSRC};							\
		for i in mirror.pl mm.pl; do				\
			${SED} -e 's:!!PREFIX!!:${PREFIX}:g' $$i >$$i.BAK;\
			${MV} -f $$i.BAK $$i;				\
		done
	
pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/mirror

post-install:
	@if [ ! -f ${PREFIX}/lib/mirror/mirror.defaults ]; then \
	    ${CP} -p \
		${PREFIX}/lib/mirror/mirror.defaults.dist \
		${PREFIX}/lib/mirror/mirror.defaults; \
	fi

.include "../../mk/bsd.pkg.mk"
