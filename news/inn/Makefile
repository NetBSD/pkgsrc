# $NetBSD: Makefile,v 1.1 1998/09/05 03:21:11 garbled Exp $

DISTNAME=		inn-2.1
CATEGORIES=		news
MASTER_SITES=		ftp://wuarchive.wustl.edu/packages/news/transport/inn/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.isc.org/inn.html

BUILD_DEPENDS+=		bison:../../devel/bison

CONFLICTS+=		nntpclnt-*

INN_SPOOL?=		/var/spool/news

USE_PERL5=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-perl --with-spool-dir=${INN_SPOOL}
CONFIGURE_ARGS+=	--with-tmp-path=/tmp
GNU_CONFIGURE=		yes

post-patch:
	${SED} -e 's@XXXINN_SPOOLXXX@${INN_SPOOL}@g' \
	-e 's@XXXPREFIXXXX@${PREFIX}@g' <${PKGDIR}/install >${PKGDIR}/INSTALL

post-install:
	${MKDIR} ${PREFIX}/share/examples/inn
	${CP} -R ${WRKSRC}/samples/* ${PREFIX}/share/examples/inn

.include "../../mk/bsd.pkg.mk"
