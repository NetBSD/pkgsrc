# $NetBSD: Makefile,v 1.8 1999/07/29 20:27:19 tron Exp $

DISTNAME=		inn-2.2
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.isc.org/isc/inn/ \
			ftp://ftp.sunet.se/pub/news/nntp/inn/ \
			ftp://ftp.fu-berlin.de/unix/news/inn/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.isc.org/inn.html

BUILD_DEPENDS+=		bison:../../devel/bison

CONFLICTS+=		nntpclnt-*

INN_DATA_DIR?=		/var/news

USE_PERL5=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-perl --with-tmp-path=/tmp \
			--with-sendmail=/usr/sbin/sendmail \
			--with-db-dir=${INN_DATA_DIR}/db \
			--with-etc-dir=${INN_DATA_DIR}/etc \
			--with-log-dir=${INN_DATA_DIR}/log \
			--with-run-dir=${INN_DATA_DIR}/run \
			--with-spool-dir=${INN_DATA_DIR}/spool
CONFIGURE_ENV+=		_PATH_PERL=${LOCALBASE}/bin/perl

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

post-build:
	${SED} -e 's#@@INN_DATA_DIR@@#${INN_DATA_DIR}#g' \
	       -e 's#@@PREFIX@@#${PREFIX}#g' \
	        ${FILESDIR}/innd.sh >${WRKDIR}/innd.sh
.for FILE in DEINSTALL INSTALL
	${SED} -e 's#@@INN_DATA_DIR@@#${INN_DATA_DIR}#g' \
	       -e 's#@@PREFIX@@#${PREFIX}#g' \
	        ${PKGDIR}/${FILE} >${WRKDIR}/${FILE}
.endfor

pre-install:
	${MKDIR} ${INN_DATA_DIR} ${PREFIX}/etc/nntp ${PREFIX}/libexec/inn

post-install:
	${LN} -s ../libexec/inn/inews ${PREFIX}/bin/inews
	${MKDIR} ${PREFIX}/share/examples/inn
	for FILE in `ls -1 ${WRKSRC}/samples/* | \
		     ${EGREP} -v '\.(in|orig)$'`; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/examples/inn; \
	done
	cd ${WRKSRC}/site && \
	${INSTALL_SCRIPT} ${WRKDIR}/innd.sh ${PREFIX}/etc/rc.d
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
