# NetBSD: Makefile,v 1.11 2000/05/19 07:34:33 itohy Exp $

DISTNAME=		pks-0.9.4
CATEGORIES=		security www
MASTER_SITES+=		http://www.mit.edu/people/marc/pks/
MASTER_SITES+=		ftp://ftp.neonramp.com/pub/pksd/

PATCH_SITES+=		http://www.mit.edu/people/marc/pks/
PATCH_SITES+=		ftp://ftp.neonramp.com/pub/pksd/
PATCHFILES=		pks094-patch2 \
			pks094-patch3
PATCH_DIST_STRIP=	-p1

MAINTAINER=		burgess@neonramp.com
HOMEPAGE=		http://www.mit.edu/people/marc/pks/

DEPENDS+=		db-*:../../databases/db

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/pks
CONFIGURE_ARGS+=	--localstatedir=/var/pks
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/examples

post-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/pksd.sh > ${WRKDIR}/pksd.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pksd.sh ${PREFIX}/etc/rc.d
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
