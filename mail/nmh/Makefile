# $NetBSD: Makefile,v 1.21 1999/02/20 22:48:34 hubertf Exp $
# FreeBSD Id: Makefile,v 1.2 1997/08/04 06:51:28 markm Exp
#

DISTNAME=	nmh-0.27
CATEGORIES=	mail
MASTER_SITES=   ftp://ftp.math.gatech.edu/pub/nmh/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.math.gatech.edu/nmh/

# Mail Transport Agent - either "smtp" or "sendmail"
NMH_MTA?=	smtp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --libexecdir=${PREFIX}/libexec/nmh \
		--sysconfdir=${PREFIX}/etc/nmh --enable-nmh-pop \
		--with-mts=${NMH_MTA}

# Since we patch the autoconf files as well as their outputs, avoid attempt
# to regenerate header input files with 'autoheader' by Makefile.
post-patch:
	${ECHO} > ${WRKSRC}/stamp-h.in

post-install:
	@PKG_PREFIX='${PREFIX}' sh -f ${PKGDIR}/INSTALL

.include "../../mk/bsd.pkg.mk"
