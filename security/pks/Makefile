# $NetBSD: Makefile,v 1.9 2001/12/02 06:56:44 jlam Exp $

DISTNAME=		pks-0.9.4
CATEGORIES=		security www
MASTER_SITES+=		http://www.mit.edu/people/marc/pks/ \
			ftp://ftp.neonramp.com/pub/pksd/

PATCH_SITES=		http://www.mit.edu/people/marc/pks/ \
			ftp://ftp.neonramp.com/pub/pksd/
PATCHFILES=		pks094-patch2 \
			pks094-patch3
PATCH_DIST_STRIP=	-p1

MAINTAINER=		burgess@neonramp.com
HOMEPAGE=		http://www.mit.edu/people/marc/pks/
COMMENT=		PGP Public Key Server

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/pks
CONFIGURE_ARGS+=	--localstatedir=/var/pks
#
# pksd doesn't actually look for it's config file anywhere; it must be
# specified directly on the command-line.  Setting sysconfdir here just
# causes the example pksd.conf file to be installed at the named location.
#
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR}

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/pksd.conf ${PKG_SYSCONFDIR}/pksd.conf
RCD_SCRIPTS=	pksd
OWN_DIRS=	/var/pks /var/pks/db /var/pks/incoming

pre-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/pksd.sh > ${WRKDIR}/pksd.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pksd.sh ${PREFIX}/etc/rc.d/pksd

.include "../../databases/db/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
