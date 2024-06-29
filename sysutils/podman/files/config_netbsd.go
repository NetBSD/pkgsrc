package config

const (
	// OverrideContainersConfig holds the default config path overridden by the root user
	OverrideContainersConfig = "@PKG_SYSCONFDIR@" + _configPath

	// DefaultContainersConfig holds the default containers config path
	DefaultContainersConfig = "@PREFIX@/share/" + _configPath

	// DefaultSignaturePolicyPath is the default value for the
	// policy.json file.
	DefaultSignaturePolicyPath = "@PKG_SYSCONFDIR@/containers/policy.json"
)

var defaultHelperBinariesDir = []string{
	// pkgsrc paths
	"@PREFIX@/bin",
}
