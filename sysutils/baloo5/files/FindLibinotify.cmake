# Created by Tobias Berner <tcberner@gmail.com>
# - Try to find the Libinotify on FreeBSD
#
# Defines
#
#  LIBINOTIFY_FOUND, LIBINOTIFY_INCLUDE_DIR, LIBINOTIFY_LIBRARIES
#

FIND_PATH(LIBINOTIFY_INCLUDE_DIR sys/inotify.h )

FIND_LIBRARY(LIBINOTIFY_LIBRARIES NAMES inotify )

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LIBINOTIFY DEFAULT_MSG
                                  LIBINOTIFY_INCLUDE_DIR
                                  LIBINOTIFY_LIBRARIES )

set_package_properties(Libinotify PROPERTIES
	URL 		"https://github.com/dmatveev/libinotify-kqueue"
	DESCRIPTION 	"inotify API on the *BSD family of operating systems."
)

MARK_AS_ADVANCED(LIBINOTIFY_INCLUDE_DIR LIBINOTIFY_LIBRARIES)
