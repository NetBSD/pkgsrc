# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/29 03:41:15 rh Exp $
#
# This Makefile fragment is included by packages that use Pantomime.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(PANTOMIME_BUILDLINK2_MK)
PANTOMIME_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			Pantomime
BUILDLINK_DEPENDS.Pantomime?=		Pantomime>=1.0.5
BUILDLINK_PKGSRCDIR.Pantomime?=		../../mail/Pantomime

EVAL_PREFIX+=	BUILDLINK_PREFIX.Pantomime=Pantomime
BUILDLINK_PREFIX.Pantomime_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Charset.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Connection.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Constants.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Flags.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Folder.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/GSMD5.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/IMAPCacheManager.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/IMAPCacheObject.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/IMAPFolder.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/IMAPMessage.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/IMAPStore.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_1.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_10.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_11.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_13.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_14.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_15.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_2.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_3.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_4.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_5.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_6.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_7.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_8.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/ISO8859_9.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/InternetAddress.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/KOI8_R.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/KOI8_U.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/LocalFolder.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/LocalFolderCacheManager.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/LocalMessage.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/LocalStore.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Message.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/MimeBodyPart.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/MimeMultipart.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/MimeUtility.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/NSDataExtensions.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/NSStringExtensions.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/POP3CacheManager.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/POP3CacheObject.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/POP3Folder.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/POP3Message.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/POP3Store.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Parser.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Part.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/SMTP.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Sendmail.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Service.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Store.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/TCPConnection.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/Transport.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/URLName.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/UTF8.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/WINDOWS_1250.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/WINDOWS_1251.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/WINDOWS_1252.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/WINDOWS_1253.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/WINDOWS_1254.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/elm_defs.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/elm_lib.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Headers/Pantomime/parseaddrs.h
BUILDLINK_FILES.Pantomime+=	share/GNUstep/Local/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/gnu-gnu-gnu/libPantomime.*

.include "../../x11/gnustep-back/buildlink2.mk"

BUILDLINK_TARGETS+=	Pantomime-buildlink

Pantomime-buildlink: _BUILDLINK_USE

.endif	# PANTOMIME_BUILDLINK2_MK
