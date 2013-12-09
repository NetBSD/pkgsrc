# $NetBSD: Makefile,v 1.6 2013/12/09 14:17:48 obache Exp $

DISTNAME=	amavisd-${VERSION}
PKGNAME=	amavis-perl-${VERSION}
PKGREVISION=	10
CATEGORIES=	mail security
MASTER_SITES=	http://www.amavis.org/dist/perl/ \
		${MASTER_SITE_SOURCEFORGE:=amavis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amavis.org/
COMMENT=	Mail virus scanner

CONFLICTS+=	amavis-[0-9]*
CONFLICTS+=	amavis-perl-[0-9]*

DEPENDS+=	uvscan-[0-9]*:../../security/uvscan
DEPENDS+=	maildrop-[0-9]*:../../mail/maildrop
DEPENDS+=	tnef-[0-9]*:../../mail/tnef
DEPENDS+=	unarj-[0-9]*:../../archivers/unarj
DEPENDS+=	unrar-[0-9]*:../../archivers/unrar
DEPENDS+=	xbin-[0-9]*:../../archivers/xbin
DEPENDS+=	lha-[0-9]*:../../archivers/lha
DEPENDS+=	zoo-[0-9]*:../../archivers/zoo
DEPENDS+=	freeze-[0-9]*:../../archivers/freeze
DEPENDS+=	arc-[0-9]*:../../archivers/arc
DEPENDS+=	{perl>=5.9.3,p5-Archive-Tar-[0-9]*}:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	{perl>=5.9.3,p5-IO-Compress-[0-9]*}:../../devel/p5-IO-Compress #Compress::Zlib>=1.14
DEPENDS+=	p5-Convert-TNEF-[0-9]*:../../converters/p5-Convert-TNEF
DEPENDS+=	p5-Convert-UUlib-[0-9]*:../../converters/p5-Convert-UUlib
DEPENDS+=	p5-MIME-tools>=5.313:../../mail/p5-MIME-tools
DEPENDS+=	{perl>=5.10,p5-Net-[0-9]*}:../../net/p5-Net
DEPENDS+=	p5-Unix-Syslog-[0-9]*:../../sysutils/p5-Unix-Syslog

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

VERSION=	0.1

SMTPPORT?=	10025			# target port for scanned mails
VIRUSDIR?=	/var/log/virusmails	# where to put contaminated mails
VIRUSMAILTO?=	security		# whom to notify about viruses

GNU_CONFIGURE=	YES
PLIST_SRC=	${PKGDIR}/PLIST

USE_TOOLS+=	file perl:run unzip:run
CONFIGURE_ENV+=	file=${TOOLS_FILE_CMD:Q}

CONFIGURE_ENV+=	procmail="/usr/libexec/mail.local"

CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/amavis
CONFIGURE_ARGS+=--with-virusdir=${VIRUSDIR:Q}
CONFIGURE_ARGS+=--with-mailto=${VIRUSMAILTO:Q}
CONFIGURE_ARGS+=--enable-all
CONFIGURE_ARGS+=--with-amavisuser=amavis
CONFIGURE_ARGS+=--with-perl=${PERL5}

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/man8 share/doc/amavis

post-build:
	${SED} -e "s|/etc/amavisd.conf|${PREFIX}/etc/amavis/amavisd.conf|" \
		${WRKSRC}/amavis/amavisd > ${WRKDIR}/amavisd

do-install:
	# Program files
.if empty(PKG_OPTIONS:Mmilter)
	${INSTALL_PROGRAM} ${WRKSRC}/amavis/amavis ${DESTDIR}${PREFIX}/sbin
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd ${DESTDIR}${PREFIX}/sbin
	# Documents
	${INSTALL_DATA} ${WRKSRC}/doc/amavis.html ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/doc/amavis.png ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/doc/amavis.txt ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${FILESDIR}/LICENSE.sendmail ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.exim ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.milter ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.postfix ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.qmail ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.scanners ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/README.sendmail ${DESTDIR}${PREFIX}/share/doc/amavis
	${INSTALL_DATA} ${WRKSRC}/amavis/amavisd.conf \
		${DESTDIR}${PREFIX}/share/doc/amavis
	${SED} "s+@PREFIX@+${PREFIX}+g" < ${FILESDIR}/amavis.m4 \
		> ${WRKDIR}/amavis.m4
	${INSTALL_DATA} ${WRKDIR}/amavis.m4 ${DESTDIR}${PREFIX}/share/doc/amavis
	# Man pages
.if empty(PKG_OPTIONS:Mmilter)
	${INSTALL_DATA} ${WRKSRC}/doc/amavis.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif
	${INSTALL_DATA} ${WRKSRC}/doc/amavis-milter.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/amavisd.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/doc/amavisd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
