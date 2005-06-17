# $NetBSD: Makefile,v 1.16 2005/06/17 03:50:31 jlam Exp $

DISTNAME=	amavisd-${VERSION}
PKGNAME=	amavis-perl-${VERSION}
PKGREVISION=	1
CATEGORIES=	security mail
MASTER_SITES=	http://www.amavis.org/dist/perl/ \
		${MASTER_SITE_SOURCEFORGE:=amavis/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.amavis.org/
COMMENT=	Mail virus scanner

CONFLICTS+=	amavis-[0-9]*
CONFLICTS+=	amavis-perl-[0-9]*

DEPENDS+=	uvscan-[0-9]*:../../security/uvscan
DEPENDS+=	maildrop-[0-9]*:../../mail/maildrop
DEPENDS+=	tnef-[0-9]*:../../mail/tnef
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	unarj-[0-9]*:../../archivers/unarj
DEPENDS+=	unrar-[0-9]*:../../archivers/unrar
DEPENDS+=	xbin-[0-9]*:../../archivers/xbin
DEPENDS+=	lha-[0-9]*:../../archivers/lha
DEPENDS+=	zoo-[0-9]*:../../archivers/zoo
DEPENDS+=	freeze-[0-9]*:../../archivers/freeze
DEPENDS+=	arc-[0-9]*:../../archivers/arc
DEPENDS+=	p5-Archive-Tar-[0-9]*:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-Convert-TNEF-[0-9]*:../../converters/p5-Convert-TNEF
DEPENDS+=	p5-Convert-UUlib-[0-9]*:../../converters/p5-Convert-UUlib
DEPENDS+=	p5-MIME-tools>=5.313:../../mail/p5-MIME-tools
DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net
DEPENDS+=	p5-Unix-Syslog-[0-9]*:../../sysutils/p5-Unix-Syslog


.include "../../mk/bsd.prefs.mk"
.if defined(USE_MILTER) && ${USE_MILTER} == "YES"
DEPENDS+=	sendmail>=8.12.9nb1:../../mail/sendmail
.endif

VERSION=	0.1

SMTPPORT?=	10025			# target port for scanned mails
VIRUSDIR?=	/var/log/virusmails	# where to put contaminated mails
VIRUSMAILTO?=	security		# whom to notify about viruses

GNU_CONFIGURE=	YES
PLIST_SRC=	${PKGDIR}/PLIST

CONFIGURE_ENV+=	procmail="/usr/libexec/mail.local"
# XXX Milter needs pthreads, and configure fails looking for it
# because ${PREFIX}/include is not available in the include path.
.if defined(USE_MILTER) && ${USE_MILTER} == "YES"
CONFIGURE_ENV+=	CFLAGS="-I${PREFIX}/include"
.endif

CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/amavis
CONFIGURE_ARGS+=--with-virusdir=${VIRUSDIR}
CONFIGURE_ARGS+=--with-mailto=${VIRUSMAILTO}
CONFIGURE_ARGS+=--enable-all
CONFIGURE_ARGS+=--with-amavisuser=amavis

.if defined(USE_MILTER) && ${USE_MILTER} == "YES"
CONFIGURE_ARGS+=--enable-milter
CONFIGURE_ARGS+=--with-milter-libs=${PREFIX}/lib
CONFIGURE_ARGS+=--with-milter-includes=${PREFIX}/include
.else
CONFIGURE_ARGS+=--enable-smtp --with-smtp-port=${SMTPPORT}
PLIST_SRC+=	${PKGDIR}/PLIST.nomilter
.endif

INSTALLATION_DIRS=	sbin man/man1 man/man5 man/man8

post-build:
	${SED} -e "s|/etc/amavisd.conf|${PREFIX}/etc/amavis/amavisd.conf|" \
		${WRKSRC}/amavis/amavisd > ${WRKDIR}/amavisd

do-install:
	# Program files
.if !defined(USE_MILTER) || ${USE_MILTER} != YES
	${INSTALL_PROGRAM} ${WRKSRC}/amavis/amavis ${PREFIX}/sbin
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd ${PREFIX}/sbin
	# Documents
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/doc/amavis.html ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/doc/amavis.png ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/doc/amavis.txt ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${FILESDIR}/LICENSE.sendmail ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.exim ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.milter ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.postfix ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.qmail ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.scanners ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.sendmail ${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/amavis/amavisd.conf \
		${PREFIX}/share/doc/amavis
	${SED} "s+@PREFIX@+${PREFIX}+g" < ${FILESDIR}/amavis.m4 \
		> ${WRKDIR}/amavis.m4
	${INSTALL_DATA} ${WRKDIR}/amavis.m4 ${PREFIX}/share/doc/amavis
	# Man pages
.if !defined(USE_MILTER) || ${USE_MILTER} != YES
	${INSTALL_DATA} ${WRKSRC}/doc/amavis.1 ${PREFIX}/man/man1
.endif
	${INSTALL_DATA} ${WRKSRC}/doc/amavis-milter.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/amavisd.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/doc/amavisd.8 ${PREFIX}/man/man8

.if defined(USE_MILTER) && ${USE_MILTER} == "YES"
.include "../../mk/pthread.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
