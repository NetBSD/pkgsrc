# $NetBSD: Makefile,v 1.24 2005/07/16 01:19:16 jlam Exp $

DISTNAME=	mirror-2.9
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sunsite.org.uk/packages/mirror/
COMMENT=	Mirror packages on remote sites

WRKSRC=		${WRKDIR}
MAKEFILE=	makefile
SCRIPTS_ENV+=	PERL5=${PERL5}

USE_TOOLS+=	perl:run
REPLACE_PERL=	do_unlinks.pl mirror.pl mm.pl pkgs_to_mmin.pl

pre-configure:
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
