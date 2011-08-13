# $NetBSD: Makefile,v 1.7 2011/08/13 18:00:01 joerg Exp $

# To the poor soul who wants to update this package:
#
# This package is not an easy one.  The software depends on a lot of PERL
# modules, and even includes patches for a number of them.
#
# That said, it comes kind of stand alone, because it includes all its
# dependencies in the CPAN directory of the archive.  But of course, a number
# of said dependencies come with native code modules, and Logitech doesn't
# provide NetBSD binaries for those.
#
# The "noCPAN" tag in the archive's file name doesn't mean that the directory
# is absent, but rather that it contains no binaries.
#
# In order to make the software work, I had to define a few rules.  The PERL
# modules that use native code had to come from pkgsrc.  There's no way around
# that.
#
# The other rule is that if a module is patched (i.e., partly found under the
# lib/ directory of the archive), it has to come fully from the archive
# (otherwise there are versioning issues that immediately rise up).
#
# That said, you want to use pkgsrc modules as often as you can, but AnyEvent
# and Log had to be from the archive for the reasons I underlined, and that's
# why only those two directories are copied from the CPAN directory of the
# archive.
#
# Now, it seems that the SqueezeboxServer is still rather picky about its
# dependencies (for instance, the current version depends on exactly version
# 0.82 of p5-Audio-Scan), so while it works with the modules from pkgsrc as I
# am writing those lines, I expect a future update of a package to break the
# expectations of the SqueezeboxServer.
#
# Finally, note that the flac/faad binaries that come with the usual
# distribution of the SqueezeboxServer are patched to work better with it.  The
# versions found in pkgsrc don't have those patches;  they could be imported,
# though.
#
# On that note, good luck!
#
# -- cube

DISTNAME=	${PRODUCT:tl:S/_v/-/}-noCPAN
PKGNAME=	${DISTNAME:S/-noCPAN//}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://downloads.slimdevices.com/${PRODUCT}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logitechsqueezebox.com/
COMMENT=	Server for the family of networked audio players by Logitech

EXTRACT_SUFX=	.tgz

PRODUCT=	SqueezeboxServer_v7.5.1
PRODUCTREV=	30836
WRKSRC=		${WRKDIR}/${DISTNAME:S/-noCPAN//}-${PRODUCTREV}-noCPAN

RESTRICTED=	Firmwares and some other components cannot be redistributed
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
LICENSE=	squeezeboxserver-license

# Database server
DEPENDS+=	mysql-server-[0-9]*:../../databases/mysql51-server

# Audio converters
DEPENDS+=	wavpack-[0-9]*:../../audio/wavpack
DEPENDS+=	sox-[0-9]*:../../audio/sox
DEPENDS+=	flac-[0-9]*:../../audio/flac
DEPENDS+=	faad2-[0-9]*:../../audio/faad2

# Perl modules with native code
DEPENDS+=	p5-Audio-Scan>=0.84:../../audio/p5-Audio-Scan
DEPENDS+=	p5-Class-XSAccessor>=1.05:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-Compress-Raw-Zlib-[0-9]*:../../devel/p5-Compress-Raw-Zlib
DEPENDS+=	p5-DBD-mysql>=3.0002:../../databases/p5-DBD-mysql
DEPENDS+=	p5-DBI>=1.608:../../databases/p5-DBI
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-EV>=3.8:../../devel/p5-EV
DEPENDS+=	p5-Encode-Detect-[0-9]*:../../textproc/p5-Encode-Detect
DEPENDS+=	p5-GD>=2.41:../../graphics/p5-GD
DEPENDS+=	p5-HTML-Parser>=3.60:../../www/p5-HTML-Parser
DEPENDS+=	p5-JSON-XS>=2.232:../../converters/p5-JSON-XS
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-XML-Parser>=2.36:../../textproc/p5-XML-Parser
DEPENDS+=	p5-YAML-Syck>=1.05:../../textproc/p5-YAML-Syck

# Perl modules without native code
DEPENDS+=	p5-Cache-Cache>=1.04:../../devel/p5-Cache-Cache
DEPENDS+=	p5-Class-Data-Inheritable>=0.04:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Inspector>=1.16:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-Data-URIEncode>=0.11:../../www/p5-Data-URIEncode
DEPENDS+=	p5-DBIx-Class>=0.08109:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Exporter-Lite-[0-9]*:../../devel/p5-Exporter-Lite
DEPENDS+=	p5-File-BOM>=0.13:../../devel/p5-File-BOM
DEPENDS+=	p5-File-Next>=1.02:../../devel/p5-File-Next
DEPENDS+=	p5-File-ReadBackwards-[0-9]*:../../textproc/p5-File-ReadBackwards
DEPENDS+=	p5-File-Slurp>=9999.09:../../devel/p5-File-Slurp
DEPENDS+=	p5-File-Which>=0.05:../../devel/p5-File-Which
DEPENDS+=	p5-IO-String>=1.07:../../devel/p5-IO-String
DEPENDS+=	p5-JSON-XS-VersionOneAndTwo>=0.31:../../converters/p5-JSON-XS-VersionOneAndTwo
DEPENDS+=	p5-Math-VecStat>=0.08:../../math/p5-Math-VecStat
DEPENDS+=	p5-Path-Class>=0.16:../../devel/p5-Path-Class
DEPENDS+=	p5-Proc-Background>=1.08:../../devel/p5-Proc-Background
DEPENDS+=	p5-SQL-Abstract>=1.56:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-Text-Unidecode>=0.04:../../textproc/p5-Text-Unidecode
DEPENDS+=	p5-Tie-Cache-LRU>=0.21:../../devel/p5-Tie-Cache-LRU
DEPENDS+=	p5-Tie-Cache-LRU-Expires-[0-9]*:../../devel/p5-Tie-Cache-LRU-Expires
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-Tie-LLHash>=1.003:../../devel/p5-Tie-LLHash
DEPENDS+=	p5-Tie-RegexpHash>=0.13:../../devel/p5-Tie-RegexpHash
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-URI-Find-[0-9]*:../../www/p5-URI-Find
DEPENDS+=	p5-UUID-Tiny-[0-9]*:../../devel/p5-UUID-Tiny
DEPENDS+=	p5-XML-Simple>=2.15:../../textproc/p5-XML-Simple

# Optional
#DEPENDS+=	p5-Locale-Hebrew-[0-9]*:../../somewhere/p5-Locale-Hebrew

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL=	slimserver.pl scanner.pl

USE_TOOLS+=	pax sed

SBS_USER?=		slimuser
SBS_GROUP?=		${SBS_USER}
PKG_USERS_VARS+=	SBS_USER
PKG_GROUPS_VARS+=	SBS_GROUP
PKG_USERS+=		${SBS_USER}:${SBS_GROUP}
PKG_GROUPS+=		${SBS_GROUP}

SBS_LIBSUBDIR=		lib/squeezeboxserver
SBS_SHARESUBDIR=	share/squeezeboxserver
INSTALLATION_DIRS+=	${SBS_LIBSUBDIR} ${SBS_SHARESUBDIR} libexec
OWN_DIRS+=		${SBS_VARDIR}
OWN_DIRS_PERMS+=	${SBS_LOGDIR}	${SBS_USER}	${SBS_GROUP}	0755
OWN_DIRS_PERMS+=	${SBS_PREFSDIR}	${SBS_USER}	${SBS_GROUP}	0755
OWN_DIRS_PERMS+=	${SBS_CACHEDIR}	${SBS_USER}	${SBS_GROUP}	0755

PKG_SYSCONFSUBDIR=	squeezeboxserver
SBS_LIBDIR=		${PREFIX}/${SBS_LIBSUBDIR}
SBS_SHAREDIR=		${PREFIX}/${SBS_SHARESUBDIR}
SBS_LOGDIR=		${VARBASE}/log/squeezeboxserver
SBS_VARDIR=		${VARBASE}/lib/squeezeboxserver
SBS_PREFSDIR=		${SBS_VARDIR}/prefs
SBS_CACHEDIR=		${SBS_VARDIR}/cache

SBS_GOTOSHARE=		Firmware Graphics HTML IR MySQL SQL \
			Changelog* Installation.txt License* \
			convert.conf modules.conf revision.txt strings.txt \
			types.conf
SBS_GOTOLIB=		CPAN/AnyEvent CPAN/Log lib Plugins Slim \
			slimserver.pl scanner.pl

SBS_COPY=		SBS_GOTOSHARE SBS_SHARESUBDIR \
			SBS_GOTOLIB SBS_LIBSUBDIR

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Configuring default pkgsrc paths
SUBST_FILES.paths=	Slim/Utils/OS/Custom.pm
SUBST_VARS.paths=	PREFIX PKG_SYSCONFDIR SBS_SHAREDIR SBS_LOGDIR \
			SBS_PREFSDIR SBS_CACHEDIR SBS_LIBDIR

CONF_FILES+=	${SBS_SHAREDIR}/types.conf ${PKG_SYSCONFDIR}/types.conf \
		${SBS_SHAREDIR}/modules.conf ${PKG_SYSCONFDIR}/modules.conf \
		${SBS_SHAREDIR}/convert.conf ${PKG_SYSCONFDIR}/convert.conf

BUILD_DEFS+=	VARBASE SBS_USER SBS_GROUP

RCD_SCRIPTS=	squeezeboxserver
FILES_SUBST+=	SBS_LIBDIR=${SBS_LIBDIR} SBS_USER=${SBS_USER} SBS_GROUP=${SBS_GROUP}
FILES_SUBST+=	SBS_VARDIR=${SBS_VARDIR} PERL5=${PERL5}

CHECK_INTERPRETER_SKIP=	${SBS_LIBSUBDIR}/lib/* ${SBS_LIBSUBDIR}/CPAN/* \
			${SBS_SHARESUBDIR}/HTML/*

do-configure:
	cp ${.CURDIR}/files/Custom.pm ${WRKSRC}/Slim/Utils/OS/Custom.pm

do-build:
	chmod -R +rX ${WRKSRC}

do-install:
.for _list_ _dir_ in ${SBS_COPY}
	cd ${WRKSRC} && ${FIND} ${${_list_}} -type f ! -name '*.orig' 2>/dev/null | \
	    pax -rw -pm ${DESTDIR}${PREFIX}/${${_dir_}}
.endfor

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
