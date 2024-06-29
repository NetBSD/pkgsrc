//go:build netbsd

package ignition

func getLocalTimeZone() (string, error) {
	return "", nil
}
