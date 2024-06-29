//go:build netbsd

package types

const (
	// these are default path for run and graph root for rootful users
	// for rootless path is constructed via getRootlessStorageOpts
	defaultRunRoot   string = "@VARBASE@/run/containers/storage"
	defaultGraphRoot string = "@VARBASE@/db/containers/storage"
	SystemConfigFile        = "@PREFIX@/share/containers/storage.conf"
)

// defaultConfigFile path to the system wide storage.conf file
var (
	defaultOverrideConfigFile = "@PKG_SYSCONFDIR@/containers/storage.conf"
)

// canUseRootlessOverlay returns true if the overlay driver can be used for rootless containers
func canUseRootlessOverlay(home, runhome string) bool {
	return false
}
